__int64 __fastcall synx_global_init_coredata(int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // w19
  __int64 v9; // x4
  __int64 v10; // x5
  __int64 result; // x0
  __int64 v12; // x8
  _DWORD *v13; // x20
  __int64 v14; // x5
  __int64 v15; // x5
  __int64 v16; // x8
  __int64 v17; // x0
  unsigned int v18; // w20
  _QWORD v19[2]; // [xsp+10h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = 0;
  if ( synx_gmem_2 )
  {
    v6 = (unsigned __int16)a1;
    if ( (unsigned int)(unsigned __int16)a1 - 1 >= 0xFFF )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_27C7E, &unk_29207, "synx_global_init_coredata", 310, (unsigned __int16)a1, a6);
      result = 4294967274LL;
    }
    else
    {
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        result = ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, v19);
        if ( !(_DWORD)result )
        {
          v12 = synx_gmem_2;
LABEL_15:
          v13 = (_DWORD *)(v12 + glcoredata_size * v6);
          v14 = (unsigned int)*v13;
          if ( (_DWORD)v14 || *((_WORD *)v13 + 4) || *((_WORD *)v13 + 6) || v13[1] || *((_WORD *)v13 + 8) )
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_260DE, &unk_29207, "synx_global_init_coredata", 334, v6, v14);
            if ( (get_ipclite_feature(4) & 1) != 0 )
            {
              ipclite_global_spin_unlock((unsigned __int8)a1, v19);
              result = 4294967274LL;
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
                  v15);
                v16 = synx_gmem_2;
              }
              v17 = synx_hwlock;
              *(_WORD *)(v16 + 12) = 8;
              _hwspin_unlock(v17, 1, v19);
              result = 4294967274LL;
            }
          }
          else if ( *((_QWORD *)v13 + 4) )
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_288BD, &unk_29207, "synx_global_init_coredata", 340, v6, v14);
            synx_gmem_unlock(v6, (__int64)v19);
            result = 4294967274LL;
          }
          else
          {
            memset(v13, 0, (unsigned int)glcoredata_size);
            *((_WORD *)v13 + 4) = 1;
            *((_WORD *)v13 + 6) = 1;
            *v13 = 1;
            v13[1] = a1;
            if ( a2 )
              *((_QWORD *)v13 + 4) = a2;
            synx_gmem_unlock(v6, (__int64)v19);
            result = 0;
          }
          goto LABEL_29;
        }
      }
      else if ( synx_hwlock )
      {
        result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v19);
        if ( !(_DWORD)result )
        {
          v12 = synx_gmem_2;
          *(_WORD *)(synx_gmem_2 + 12) = 0;
          goto LABEL_15;
        }
      }
      else
      {
        if ( (synx_debug & 1) != 0 )
          printk(&unk_2AE54, &unk_29207, "synx_gmem_lock", 54, v9, v10);
        result = 4294967274LL;
      }
      if ( (synx_debug & 1) != 0 )
      {
        v18 = result;
        printk(&unk_2981B, &unk_29207, "synx_global_init_coredata", 316, v6, v10);
        result = v18;
      }
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_267BF, &unk_29207, "synx_global_init_coredata", 305, a5, a6);
    result = 4294967284LL;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
