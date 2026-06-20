__int64 __fastcall wlan_ipa_flush(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x8
  __int64 *v3; // x20
  unsigned __int64 StatusReg; // x21
  __int64 *v5; // x9
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x8

  if ( (**(_BYTE **)(result + 1464) & 1) != 0 )
  {
    v1 = result;
    cancel_work_sync(result + 3312);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v2 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v2 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v2 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v1 + 3360);
      v3 = *(__int64 **)(v1 + 3288);
      if ( v3 )
      {
LABEL_6:
        StatusReg = _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v5 = *(__int64 **)(v1 + 3296);
          --*(_DWORD *)(v1 + 3304);
          if ( v3 == v5 )
          {
            v6 = 0;
            *(_QWORD *)(v1 + 3296) = 0;
          }
          else
          {
            v6 = *v3;
          }
          *(_QWORD *)(v1 + 3288) = v6;
          *v3 = 0;
          v7 = *(_QWORD *)(v1 + 3368);
          if ( (v7 & 1) != 0 )
          {
            *(_QWORD *)(v1 + 3368) = v7 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v1 + 3360);
            if ( (v3[5] & 1) != 0 )
              goto LABEL_13;
          }
          else
          {
            raw_spin_unlock(v1 + 3360);
            if ( (v3[5] & 1) != 0 )
              goto LABEL_13;
          }
          if ( *((_BYTE *)v3 + 64) != 1 )
          {
            v8 = v3[7];
            if ( v8 )
              ipa_free_skb(v8);
            goto LABEL_14;
          }
LABEL_13:
          dev_kfree_skb_any_reason(v3, 1);
LABEL_14:
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v1 + 3360);
            v3 = *(__int64 **)(v1 + 3288);
            if ( !v3 )
              break;
          }
          else
          {
            raw_spin_lock_bh(v1 + 3360);
            *(_QWORD *)(v1 + 3368) |= 1uLL;
            v3 = *(__int64 **)(v1 + 3288);
            if ( !v3 )
              break;
          }
        }
      }
    }
    else
    {
      raw_spin_lock_bh(v1 + 3360);
      *(_QWORD *)(v1 + 3368) |= 1uLL;
      v3 = *(__int64 **)(v1 + 3288);
      if ( v3 )
        goto LABEL_6;
    }
    v9 = *(_QWORD *)(v1 + 3368);
    if ( (v9 & 1) != 0 )
    {
      *(_QWORD *)(v1 + 3368) = v9 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(v1 + 3360);
    }
    else
    {
      return raw_spin_unlock(v1 + 3360);
    }
  }
  return result;
}
