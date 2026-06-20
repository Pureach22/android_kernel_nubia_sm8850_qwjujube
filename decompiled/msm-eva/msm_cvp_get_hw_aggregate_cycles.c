__int64 __fastcall msm_cvp_get_hw_aggregate_cycles(int a1)
{
  __int64 v1; // x23
  __int64 *v3; // x24
  unsigned int v4; // w19
  unsigned __int64 StatusReg; // x28
  int v6; // w8
  unsigned __int64 v7; // x8

  v1 = *(_QWORD *)(cvp_driver + 48);
  if ( v1 )
  {
    mutex_lock(v1 + 48);
    v3 = *(__int64 **)(v1 + 280);
    if ( v3 != (__int64 *)(v1 + 280) )
    {
      v4 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( (v3[41] & 0xFFFFFFFE) != 8 )
        {
          v6 = *((_DWORD *)v3 + 3716);
          if ( v6
            || *((_DWORD *)v3 + 3715)
            || *((_DWORD *)v3 + 3714)
            || *((_DWORD *)v3 + 3717)
            || *((_DWORD *)v3 + 3718)
            || *((_DWORD *)v3 + 3719)
            || *((_DWORD *)v3 + 3720)
            || *((_DWORD *)v3 + 3721)
            || *((_DWORD *)v3 + 3722) )
          {
            if ( a1 <= 3 )
            {
              if ( a1 > 1 )
              {
                if ( a1 != 2 )
                  v6 = *((_DWORD *)v3 + 3717);
              }
              else if ( a1 )
              {
                if ( a1 != 1 )
                {
LABEL_34:
                  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                    printk(
                      &unk_8DC41,
                      *(unsigned int *)(StatusReg + 1800),
                      *(unsigned int *)(StatusReg + 1804),
                      &unk_8E7CE);
                  goto LABEL_6;
                }
                v6 = *((_DWORD *)v3 + 3715);
              }
              else
              {
                v6 = *((_DWORD *)v3 + 3714);
              }
            }
            else if ( a1 <= 5 )
            {
              if ( a1 == 4 )
                v6 = *((_DWORD *)v3 + 3718);
              else
                v6 = *((_DWORD *)v3 + 3719);
            }
            else
            {
              switch ( a1 )
              {
                case 6:
                  v6 = *((_DWORD *)v3 + 3720);
                  break;
                case 7:
                  v6 = *((_DWORD *)v3 + 3721);
                  break;
                case 8:
                  v6 = *((_DWORD *)v3 + 3722);
                  break;
                default:
                  goto LABEL_34;
              }
            }
            v4 += v6;
          }
        }
LABEL_6:
        v3 = (__int64 *)*v3;
        if ( v3 == (__int64 *)(v1 + 280) )
          goto LABEL_41;
      }
    }
    v4 = 0;
LABEL_41:
    mutex_unlock(v1 + 48);
  }
  else
  {
    v4 = -22;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v7 = _ReadStatusReg(SP_EL0);
      printk(&unk_9647C, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
    }
  }
  return v4;
}
