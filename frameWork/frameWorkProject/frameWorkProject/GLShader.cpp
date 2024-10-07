#include "GLShader.h"
#include <sstream>
#include <fstream>

GL::GLShader::GLShader(const string& vs, const string& fs)
{
	createShaderProgram( vs, fs );
}

GL::GLShader::~GLShader()
{
	glDeleteProgram(m_program);
}

void GL::GLShader::use()
{
	glUseProgram(m_program);
}

void GL::GLShader::setInt(const char* name, int val)
{
	GLuint loca = glGetUniformLocation(m_program, name);
	glUniform1i(loca, val);
}

void GL::GLShader::setFloat(const char* name, float val)
{
	GLuint loca = glGetUniformLocation(m_program, name);
	glUniform1f(loca, val);
}

void GL::GLShader::setVec3(const char* name, const glm::vec3& val)
{
	GLuint loca = glGetUniformLocation(m_program, name);
	glUniform3fv(loca, 1, glm::value_ptr(val));
}

void GL::GLShader::setVec4(const char* name, const glm::vec4& val)
{
	GLuint loca = glGetUniformLocation(m_program, name);
	glUniform4fv(loca, 1, glm::value_ptr(val));
}

void GL::GLShader::setMat4(const char* name, const glm::mat4& mat)
{
	GLuint loca = glGetUniformLocation(m_program, name);
	glUniformMatrix4fv(loca, 1,GL_FALSE, glm::value_ptr(mat));
}

void GL::GLShader::createShaderProgram(const string& vs, const string& fs)
{
	fstream vfile, ffile;
	vfile.exceptions(ios::failbit | ios::badbit);
	ffile.exceptions(ios::failbit | ios::badbit);

	try
	{
		vfile.open(vs);
		ffile.open(fs);
		stringstream vbuf,fbuf;
		vbuf << vfile.rdbuf();
		fbuf << ffile.rdbuf();
		string vstring, fstring;
		vstring = vbuf.str();
		fstring = fbuf.str();
		const char* vchar = vstring.c_str();
		const char* fchar = fstring.c_str();

		GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vShader, 1, &vchar, 0);
		glCompileShader(vShader);
		checkState(vShader);

		GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fShader, 1, &fchar, 0);
		glCompileShader(fShader);
		checkState(fShader);

		m_program = glCreateProgram();
		glAttachShader(m_program, vShader);
		glAttachShader(m_program, fShader);
		glLinkProgram(m_program);
		checkState(m_program, false);

		vfile.close();
		ffile.close();

		glDeleteShader(vShader);
		glDeleteShader(fShader);
	}
	catch (const std::exception&)
	{
		cout << "shader file read faild \n";
	}
}

bool GL::GLShader::checkState(GLuint handle, bool isShader)
{
	if (isShader)
	{
		GLint suc;
		glGetShaderiv(handle, GL_COMPILE_STATUS, &suc);
		if (!suc)
		{
			int len = 0;
			char s[1024]{ 0 };
			glGetShaderInfoLog(handle, 1024, &len, s);
			cout << "Shader faild: " << s<<"\n";
		}
	}
	else
	{
		GLint suc;
		glGetProgramiv(handle, GL_LINK_STATUS, &suc);
		if (!suc)
		{
			int len = 0;
			char s[1024]{ 0 };
			glGetProgramInfoLog(handle, 1024, &len, s);
			cout << "Program faild: " << s << "\n";
		}
	}
	return true;
}
