	#include <iostream>
	#include <string>
	int comparePath(const std::string &path1, const std::string &path2)
	{
  	int count = 0;
		unsigned int i = 1;
		for (; i < path1.size(); i++)
		{
			if (path1[i] != path2[i])
			{
				if (path1[i] != '/' || (path2[i] != '/' && path2[i] != '\0'))
					return (0);
				else
					break;
			}
			if ((path1[i] == '/' && path2[i] == '/'))
			{
				count++;
			}
		}
		if (path1.size() == 1 && path1[0] == '/')
		{
			count++;
			return (count);
		}
		if (path1[i] == '/' && path2[i] == '/')
		{
			count++;
			count++;
			if (path1[i + 1] != '\0')
				count = 0;
			return (count);
		}
		if ((path1[i - 1] == '/' && path2[i - 1] == '/'))
		{
			count++;
			return(count);
		}
		if (path1[i] == '/' && path2[i] == '\0')
		{
			count++;
			count++;
			if (path1[i + 1] != '\0')
				count = 0;
			return (count);
		}
		if (path1[i] == '\0' && path2[i] == '/')
		{
			count++;
			count++;
			return (count);
		}
		//std::cout << static_cast<int>(path1[i]) << std::endl;
		if ((path1[i - 1] != '/' && path1[i] == '\0') && (path2[i - 1] != '/' && path2[i] == '\0'))
		{
			count++;
			count++;
			return (count);
		}
		if (path1.size() >= path2.size() + 1)
			count = 0;
		if (path2.size() >= path1.size() + 1)
			count = 0;
			return (count);
	}

	int main()
	{
		std::cout << 	comparePath("/", "/location/ss") << std::endl;
	}
