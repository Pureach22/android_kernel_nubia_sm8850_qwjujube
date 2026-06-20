__int64 __fastcall synx_global_get_subscribed_cores(
        unsigned int a1,
        _BYTE *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  __int16 v13; // w10
  __int64 v14; // x5
  unsigned int v15; // w20
  __int64 v16; // x8
  __int64 v17; // x0
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  if ( synx_gmem_2 )
  {
    if ( a1 - 1 <= 0xFFE && a2 && (unsigned __int64)a2 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        result = ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, v18);
        if ( !(_DWORD)result )
        {
          v11 = synx_gmem_2;
          goto LABEL_17;
        }
      }
      else if ( synx_hwlock )
      {
        result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v18);
        if ( !(_DWORD)result )
        {
          v11 = synx_gmem_2;
          *(_WORD *)(synx_gmem_2 + 12) = 0;
LABEL_17:
          v12 = v11 + glcoredata_size * a1;
          v13 = *(_WORD *)(v12 + 12);
          if ( (v13 & 1) != 0 )
          {
            *a2 = 1;
            v13 = *(_WORD *)(v12 + 12);
            if ( (v13 & 2) == 0 )
            {
LABEL_19:
              if ( (v13 & 4) == 0 )
                goto LABEL_20;
              goto LABEL_35;
            }
          }
          else if ( (v13 & 2) == 0 )
          {
            goto LABEL_19;
          }
          a2[1] = 1;
          v13 = *(_WORD *)(v12 + 12);
          if ( (v13 & 4) == 0 )
          {
LABEL_20:
            if ( (v13 & 8) == 0 )
              goto LABEL_21;
            goto LABEL_36;
          }
LABEL_35:
          a2[2] = 1;
          v13 = *(_WORD *)(v12 + 12);
          if ( (v13 & 8) == 0 )
          {
LABEL_21:
            if ( (v13 & 0x10) == 0 )
              goto LABEL_22;
            goto LABEL_37;
          }
LABEL_36:
          a2[3] = 1;
          v13 = *(_WORD *)(v12 + 12);
          if ( (v13 & 0x10) == 0 )
          {
LABEL_22:
            if ( (v13 & 0x20) == 0 )
              goto LABEL_23;
            goto LABEL_38;
          }
LABEL_37:
          a2[4] = 1;
          v13 = *(_WORD *)(v12 + 12);
          if ( (v13 & 0x20) == 0 )
          {
LABEL_23:
            if ( (v13 & 0x40) == 0 )
              goto LABEL_24;
            goto LABEL_39;
          }
LABEL_38:
          a2[5] = 1;
          v13 = *(_WORD *)(v12 + 12);
          if ( (v13 & 0x40) == 0 )
          {
LABEL_24:
            if ( (v13 & 0x80) == 0 )
            {
LABEL_26:
              if ( (get_ipclite_feature(4) & 1) != 0 )
              {
                ipclite_global_spin_unlock((unsigned __int8)a1, v18);
              }
              else
              {
                v16 = synx_gmem_2;
                if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
                {
                  printk(
                    &unk_29DF8,
                    "warn",
                    "synx_gmem_lock_owner_clear",
                    42,
                    *(unsigned __int16 *)(synx_gmem_2 + 12),
                    v14);
                  v16 = synx_gmem_2;
                }
                v17 = synx_hwlock;
                *(_WORD *)(v16 + 12) = 8;
                _hwspin_unlock(v17, 1, v18);
              }
              result = 0;
              goto LABEL_46;
            }
LABEL_25:
            a2[7] = 1;
            goto LABEL_26;
          }
LABEL_39:
          a2[6] = 1;
          if ( (*(_WORD *)(v12 + 12) & 0x80) == 0 )
            goto LABEL_26;
          goto LABEL_25;
        }
      }
      else
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v8, v9);
        result = 4294967274LL;
      }
      if ( (synx_debug & 1) != 0 )
      {
        v15 = result;
        printk(&unk_2981B, &unk_29207, "synx_global_get_subscribed_cores", 457, a1, v9);
        result = v15;
      }
    }
    else
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_29CFB, &unk_29207, "synx_global_get_subscribed_cores", 451, a2, a1);
      result = 4294967274LL;
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_get_subscribed_cores", 446, a5, a6);
    result = 4294967284LL;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
