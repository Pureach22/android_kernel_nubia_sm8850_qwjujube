__int64 __fastcall dp_prealloc_get_context_memory(int a1, unsigned __int64 a2)
{
  int *v3; // x9
  __int64 v4; // x8

  if ( g_dp_context_allocs != a1
    || (byte_16B70 & 1) != 0
    || (v3 = &g_dp_context_allocs, (v4 = qword_16B78) == 0)
    || (unsigned int)dword_16B6C < a2 )
  {
    if ( dword_16B80 != a1
      || (byte_16B88 & 1) != 0
      || (v3 = &dword_16B80, (v4 = qword_16B90) == 0)
      || (unsigned int)dword_16B84 < a2 )
    {
      if ( dword_16B98 != a1
        || (byte_16BA0 & 1) != 0
        || (v3 = &dword_16B98, (v4 = qword_16BA8) == 0)
        || (unsigned int)dword_16B9C < a2 )
      {
        if ( dword_16BB0 != a1
          || (byte_16BB8 & 1) != 0
          || (v3 = &dword_16BB0, (v4 = qword_16BC0) == 0)
          || (unsigned int)dword_16BB4 < a2 )
        {
          if ( dword_16BC8 != a1
            || (byte_16BD0 & 1) != 0
            || (v3 = &dword_16BC8, (v4 = qword_16BD8) == 0)
            || (unsigned int)dword_16BCC < a2 )
          {
            if ( dword_16BE0 != a1
              || (byte_16BE8 & 1) != 0
              || (v3 = &dword_16BE0, (v4 = qword_16BF0) == 0)
              || (unsigned int)dword_16BE4 < a2 )
            {
              if ( dword_16BF8 != a1
                || (byte_16C00 & 1) != 0
                || (v3 = &dword_16BF8, (v4 = qword_16C08) == 0)
                || (unsigned int)dword_16BFC < a2 )
              {
                if ( dword_16C10 != a1
                  || (byte_16C18 & 1) != 0
                  || (v3 = &dword_16C10, (v4 = qword_16C20) == 0)
                  || (unsigned int)dword_16C14 < a2 )
                {
                  if ( dword_16C28 != a1 )
                    return 0;
                  if ( (byte_16C30 & 1) != 0 )
                    return 0;
                  v3 = &dword_16C28;
                  if ( !qword_16C38 || (unsigned int)dword_16C2C < a2 )
                    return 0;
                  v4 = qword_16C38;
                }
              }
            }
          }
        }
      }
    }
  }
  *((_BYTE *)v3 + 8) = 1;
  return v4;
}
