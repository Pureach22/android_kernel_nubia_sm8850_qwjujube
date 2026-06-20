__int64 __fastcall ieee80211_recalc_offload(__int64 result)
{
  __int64 *v1; // x19
  __int64 v2; // x22
  __int64 v3; // x21
  __int64 (__fastcall *v4)(__int64, __int64 *); // x8
  __int64 *v5; // x8
  __int64 v6; // x8
  int v7; // w8
  void *v8; // x9
  __int64 *i; // x8
  void *v10; // x12
  __int64 v11; // x11
  int v12; // w11
  __int64 v13; // x8
  __int64 v14; // x1

  if ( (*(_QWORD *)(result + 96) & 0x1000000000000LL) != 0 )
  {
    v1 = *(__int64 **)(result + 4616);
    v2 = result + 4616;
    if ( v1 != (__int64 *)(result + 4616) )
    {
      _ReadStatusReg(SP_EL0);
      while ( (v1[204] & 1) == 0 )
      {
LABEL_4:
        v1 = (__int64 *)*v1;
        if ( v1 == (__int64 *)v2 )
          return result;
      }
      v3 = v1[202];
      result = ieee80211_set_sdata_offload_flags(v1);
      if ( (result & 1) != 0 )
      {
        if ( (*(_BYTE *)(v1[202] + 1471) & 1) == 0
          && (v1[203] & 0x20) == 0
          && (drv_update_vif_offload___already_done & 1) == 0 )
        {
          v13 = v1[201];
          if ( v13 )
            v14 = v13 + 296;
          else
            v14 = (__int64)(v1 + 205);
          drv_update_vif_offload___already_done = 1;
          result = _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v14);
          __break(0x800u);
        }
        if ( *(_QWORD *)(*(_QWORD *)(v3 + 464) + 856LL) )
        {
          v4 = *(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)(v3 + 464) + 856LL);
          if ( *((_DWORD *)v4 - 1) != 1098857213 )
            __break(0x8228u);
          result = v4(v3, v1 + 590);
        }
        v5 = v1;
        if ( *((_DWORD *)v1 + 1180) != 4 )
          goto LABEL_17;
        v6 = v1[254];
        if ( v6 )
        {
          v5 = (__int64 *)(v6 - 2264);
LABEL_17:
          if ( (*(_QWORD *)(v1[202] + 96) & 0x1000000000000LL) != 0 && (v5[590] & 0xFFFFFFFE) == 2 )
          {
            v7 = *((_DWORD *)v5 + 1469);
            if ( *((_BYTE *)v1 + 81) == 1 )
              v7 &= (unsigned __int8)(v7 & 2) >> 1;
            if ( (v7 & 1) != 0 )
              v8 = &ieee80211_dataif_8023_ops;
            else
              v8 = &ieee80211_dataif_ops;
            *(_QWORD *)(v1[201] + 8) = v8;
          }
        }
      }
      for ( i = *(__int64 **)(v3 + 4616); i != (__int64 *)(v3 + 4616); i = (__int64 *)*i )
      {
        if ( *((_DWORD *)i + 1180) == 4 )
        {
          v11 = i[254];
          if ( (__int64 *)v11 == v1 + 283
            && (*(_QWORD *)(i[202] + 96) & 0x1000000000000LL) != 0
            && (*(_DWORD *)(v11 + 2456) & 0xFFFFFFFE) == 2 )
          {
            v12 = *(_DWORD *)(v11 + 3612);
            if ( *((_BYTE *)i + 81) == 1 )
              v12 &= (unsigned __int8)(v12 & 2) >> 1;
            if ( (v12 & 1) != 0 )
              v10 = &ieee80211_dataif_8023_ops;
            else
              v10 = &ieee80211_dataif_ops;
            *(_QWORD *)(i[201] + 8) = v10;
          }
        }
      }
      goto LABEL_4;
    }
  }
  return result;
}
