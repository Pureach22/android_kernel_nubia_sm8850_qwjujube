__int64 __fastcall dp_display_get_displays(__int64 a1, _QWORD *a2, int a3)
{
  __int64 result; // x0
  __int64 v5; // x0

  if ( a2 )
  {
    if ( a3 <= 0 || !g_dp_display )
      return 0;
    if ( *(_QWORD *)g_dp_display == a1 )
    {
      result = 1;
      *a2 = g_dp_display;
      if ( a3 <= 1 )
        return result;
    }
    else
    {
      result = 0;
    }
    if ( qword_293438 )
    {
      if ( *(_QWORD *)qword_293438 == a1 )
      {
        a2[(unsigned int)result] = qword_293438;
        result = (unsigned int)(result + 1);
        if ( (int)result >= a3 )
          return result;
      }
      else if ( (int)result >= a3 )
      {
        return result;
      }
      if ( qword_293440 )
      {
        if ( *(_QWORD *)qword_293440 == a1 )
        {
          a2[(unsigned int)result] = qword_293440;
          result = (unsigned int)(result + 1);
        }
        if ( (int)result < a3 && qword_293448 )
        {
          if ( *(_QWORD *)qword_293448 == a1 )
          {
            a2[(unsigned int)result] = qword_293448;
            result = (unsigned int)(result + 1);
          }
          if ( (int)result < a3 && qword_293450 )
          {
            if ( *(_QWORD *)qword_293450 == a1 )
            {
              a2[(unsigned int)result] = qword_293450;
              result = (unsigned int)(result + 1);
            }
            if ( (int)result < a3 && qword_293458 )
            {
              if ( *(_QWORD *)qword_293458 == a1 )
              {
                a2[(unsigned int)result] = qword_293458;
                result = (unsigned int)(result + 1);
              }
              if ( (int)result < a3 && qword_293460 )
              {
                if ( *(_QWORD *)qword_293460 == a1 )
                {
                  a2[(unsigned int)result] = qword_293460;
                  result = (unsigned int)(result + 1);
                }
                if ( (int)result < a3 && qword_293468 && *(_QWORD *)qword_293468 == a1 )
                {
                  a2[(unsigned int)result] = qword_293468;
                  return (unsigned int)(result + 1);
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v5 = 0;
    ipc_log_string(v5, "[e][%-4d]invalid data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_245274, "dp_display_get_displays");
    return 4294967274LL;
  }
  return result;
}
