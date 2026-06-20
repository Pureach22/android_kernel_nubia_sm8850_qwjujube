__int64 pm_subsystems_init()
{
  __int64 v0; // x27
  _DWORD *v1; // x26
  const char *v2; // x28
  __int64 result; // x0
  char **v4; // x8
  char *v5; // x8
  char *v6; // x9

  printk(&unk_9B39);
  printk(&unk_A09F);
  v0 = 0;
  v1 = &unk_9240;
  do
  {
    v2 = off_8C50[v0];
    result = strcmp("modem", v2);
    if ( (_DWORD)result )
    {
      result = strcmp("wpss", v2);
      if ( (_DWORD)result )
      {
        result = strcmp("adsp", v2);
        if ( (_DWORD)result )
        {
          result = strcmp("adsp_island", v2);
          if ( (_DWORD)result )
          {
            result = strcmp("cdsp", v2);
            if ( (_DWORD)result )
            {
              result = strcmp("slpi", v2);
              if ( (_DWORD)result )
              {
                result = strcmp("slpi_island", v2);
                if ( (_DWORD)result )
                {
                  result = strcmp("gpu", v2);
                  if ( (_DWORD)result )
                  {
                    result = strcmp("display", v2);
                    if ( (_DWORD)result )
                    {
                      result = strcmp("apss", v2);
                      if ( (_DWORD)result )
                        goto LABEL_23;
                      v4 = &off_8D20;
                    }
                    else
                    {
                      v4 = &off_8D10;
                    }
                  }
                  else
                  {
                    v4 = &off_8D00;
                  }
                }
                else
                {
                  v4 = &off_8CF0;
                }
              }
              else
              {
                v4 = &off_8CE0;
              }
            }
            else
            {
              v4 = &off_8CD0;
            }
          }
          else
          {
            v4 = &off_8CC0;
          }
        }
        else
        {
          v4 = &off_8CB0;
        }
      }
      else
      {
        v4 = &off_8CA0;
      }
    }
    else
    {
      v4 = &subsystems;
    }
    v6 = *v4;
    v5 = v4[1];
    *v1 = 1;
    *((_QWORD *)v1 - 2) = v6;
    *((_QWORD *)v1 - 1) = v5;
LABEL_23:
    ++v0;
    v1 += 12;
  }
  while ( v0 != 8 );
  return result;
}
