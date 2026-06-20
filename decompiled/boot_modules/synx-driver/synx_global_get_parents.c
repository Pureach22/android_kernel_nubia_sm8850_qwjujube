__int64 __fastcall synx_global_get_parents(unsigned int a1, _DWORD *a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v8; // x4
  __int64 v9; // x5
  __int64 result; // x0
  __int64 v11; // x4
  __int64 v12; // x8
  unsigned __int16 *v13; // x9
  _DWORD *v14; // x8
  unsigned int v15; // w21
  unsigned int v16; // w20
  __int64 v17; // x5
  __int64 v18; // x8
  __int64 v19; // x0
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  if ( a2 && synx_gmem_2 )
  {
    if ( a1 - 1 >= 0xFFF )
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_27C7E, &unk_29207, "synx_global_get_parents", 613, a1, a6);
      result = 4294967274LL;
    }
    else
    {
      if ( (get_ipclite_feature(4) & 1) != 0 )
      {
        result = ipclite_global_spin_lock_timeout((unsigned __int8)a1, 500, v20);
        if ( !(_DWORD)result )
        {
          v12 = synx_gmem_2;
LABEL_16:
          v13 = (unsigned __int16 *)(v12 + glcoredata_size * a1);
          if ( v13 )
          {
            v14 = a2;
            v15 = 0;
            *v14 = v13[8];
            v14[1] = v13[9];
            v14[2] = v13[10];
            v14[3] = v13[11];
          }
          else
          {
            if ( (synx_debug & 1) != 0 )
              printk(&unk_261D7, &unk_29207, "synx_global_get_parents_locked", 591, v11, v9);
            v15 = -12;
          }
          if ( (get_ipclite_feature(4) & 1) != 0 )
          {
            ipclite_global_spin_unlock((unsigned __int8)a1, v20);
          }
          else
          {
            v18 = synx_gmem_2;
            if ( *(_WORD *)(synx_gmem_2 + 12) && (synx_debug & 2) != 0 )
            {
              printk(&unk_29DF8, "warn", "synx_gmem_lock_owner_clear", 42, *(unsigned __int16 *)(synx_gmem_2 + 12), v17);
              v18 = synx_gmem_2;
            }
            v19 = synx_hwlock;
            *(_WORD *)(v18 + 12) = 8;
            _hwspin_unlock(v19, 1, v20);
          }
          result = v15;
          goto LABEL_33;
        }
      }
      else if ( synx_hwlock )
      {
        result = _hwspin_lock_timeout(synx_hwlock, 500, 1, v20);
        if ( !(_DWORD)result )
        {
          v12 = synx_gmem_2;
          *(_WORD *)(synx_gmem_2 + 12) = 0;
          goto LABEL_16;
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
        v16 = result;
        printk(&unk_2981B, &unk_29207, "synx_global_get_parents", 619, a1, v9);
        result = v16;
      }
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_29A4A, &unk_29207, "synx_global_get_parents", 608, a5, a6);
    result = 4294967284LL;
  }
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
