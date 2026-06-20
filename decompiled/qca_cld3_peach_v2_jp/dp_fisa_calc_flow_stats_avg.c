__int64 __fastcall dp_fisa_calc_flow_stats_avg(__int64 result)
{
  __int64 *v1; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 v5; // x21
  unsigned __int64 v6; // x20
  __int64 v7; // x26
  __int64 v8; // x8
  __int64 *v9; // x8
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x11
  unsigned __int64 v14; // x9
  int v15; // w11
  __int64 v16; // x8

  if ( *(_BYTE *)(result + 223) == 1 )
  {
    v1 = *(__int64 **)(result + 1480);
    if ( v1 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v3 = raw_spin_lock(v1 + 6);
        if ( *((_WORD *)v1 + 16) )
          goto LABEL_7;
      }
      else
      {
        v3 = raw_spin_lock_bh(v1 + 6);
        v1[7] |= 1uLL;
        if ( *((_WORD *)v1 + 16) )
        {
LABEL_7:
          v5 = *v1;
          v6 = 0;
          v7 = *v1 + 248;
          do
          {
            if ( *(_BYTE *)(v7 - 208) && *(_BYTE *)(v7 - 104) != 7 )
            {
              v3 = sched_clock(v3, v4);
              if ( (unsigned __int64)(v3 - *(_QWORD *)v7) < 0x3B9ACA00
                || (unsigned __int64)(v3 - *(_QWORD *)(v7 + 56)) > 0x3B9ACA00 )
              {
                v8 = *(_QWORD *)(v7 + 32);
                *(_BYTE *)(v7 + 72) = 0;
                *(_QWORD *)(v7 + 40) = v8;
                v9 = (__int64 *)(v7 + 64);
              }
              else
              {
                v10 = v5 + 336 * v6;
                v12 = *(_QWORD *)(v7 + 32);
                v11 = *(_QWORD *)(v7 + 40);
                *(_BYTE *)(v7 + 72) = 1;
                if ( v11 )
                {
                  v13 = *(_QWORD *)(v7 + 64);
                  *(_QWORD *)(v7 + 40) = v12;
                  v14 = 1000000000 * (v12 - v11) / (unsigned __int64)(v3 - v13);
                  v15 = *(_DWORD *)(v7 + 48);
                  if ( v15 )
                    v14 = 75 * v14 / 0x64 + (unsigned int)(25 * v15) / 0x64uLL;
                  v9 = (__int64 *)(v10 + 312);
                  *(_DWORD *)(v7 + 48) = v14;
                }
                else
                {
                  *(_QWORD *)(v7 + 40) = v12;
                  v9 = (__int64 *)(v10 + 312);
                }
              }
              *v9 = v3;
            }
            ++v6;
            v7 += 336;
          }
          while ( v6 < *((unsigned __int16 *)v1 + 16) );
        }
      }
      v16 = v1[7];
      if ( (v16 & 1) != 0 )
      {
        v1[7] = v16 & 0xFFFFFFFFFFFFFFFELL;
        return raw_spin_unlock_bh(v1 + 6);
      }
      else
      {
        return raw_spin_unlock(v1 + 6);
      }
    }
  }
  return result;
}
