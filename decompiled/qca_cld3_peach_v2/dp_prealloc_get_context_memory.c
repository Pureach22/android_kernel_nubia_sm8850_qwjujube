__int64 __fastcall dp_prealloc_get_context_memory(int a1, unsigned __int64 a2)
{
  int *v3; // x9
  __int64 v4; // x8

  if ( g_dp_context_allocs != a1
    || (byte_17490 & 1) != 0
    || (v3 = &g_dp_context_allocs, (v4 = qword_17498) == 0)
    || (unsigned int)dword_1748C < a2 )
  {
    if ( dword_174A0 != a1
      || (byte_174A8 & 1) != 0
      || (v3 = &dword_174A0, (v4 = qword_174B0) == 0)
      || (unsigned int)dword_174A4 < a2 )
    {
      if ( dword_174B8 != a1
        || (byte_174C0 & 1) != 0
        || (v3 = &dword_174B8, (v4 = qword_174C8) == 0)
        || (unsigned int)dword_174BC < a2 )
      {
        if ( dword_174D0 != a1
          || (byte_174D8 & 1) != 0
          || (v3 = &dword_174D0, (v4 = qword_174E0) == 0)
          || (unsigned int)dword_174D4 < a2 )
        {
          if ( dword_174E8 != a1
            || (byte_174F0 & 1) != 0
            || (v3 = &dword_174E8, (v4 = qword_174F8) == 0)
            || (unsigned int)dword_174EC < a2 )
          {
            if ( dword_17500 != a1
              || (byte_17508 & 1) != 0
              || (v3 = &dword_17500, (v4 = qword_17510) == 0)
              || (unsigned int)dword_17504 < a2 )
            {
              if ( dword_17518 != a1
                || (byte_17520 & 1) != 0
                || (v3 = &dword_17518, (v4 = qword_17528) == 0)
                || (unsigned int)dword_1751C < a2 )
              {
                if ( dword_17530 != a1
                  || (byte_17538 & 1) != 0
                  || (v3 = &dword_17530, (v4 = qword_17540) == 0)
                  || (unsigned int)dword_17534 < a2 )
                {
                  if ( dword_17548 != a1 )
                    return 0;
                  if ( (byte_17550 & 1) != 0 )
                    return 0;
                  v3 = &dword_17548;
                  if ( !qword_17558 || (unsigned int)dword_1754C < a2 )
                    return 0;
                  v4 = qword_17558;
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
