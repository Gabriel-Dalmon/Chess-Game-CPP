#pragma once



//------------------------------------------------------------------------------
class File {
public:
	using Byte = unsigned char;
	File();

	bool Open(const char* path, const char* openMode);
	bool Open(const wchar_t* path, const wchar_t* openMode);

	long int GetSize();

	void Read(Byte* buffer);
	void ReadChunk(Byte* buffer, int size);

	void Write(Byte* buffer, int size);

	void SetCursor(long offset, int mode);
	
	void Close();
	void Release();

	~File() {};

private:
	const char* m_path;
	long int m_size;
	FILE* m_pFile;
};