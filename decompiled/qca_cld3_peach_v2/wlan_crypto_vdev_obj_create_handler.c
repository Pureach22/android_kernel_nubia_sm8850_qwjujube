__int64 __fastcall wlan_crypto_vdev_obj_create_handler(__int64 a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x20
  __int64 v4; // x21
  unsigned __int64 StatusReg; // x8
  unsigned int v6; // w9
  int v7; // w8
  __int64 v8; // x8
  int v9; // w8
  __int64 result; // x0
  unsigned int v11; // w19

  if ( !a1 )
    return 4;
  v2 = (_QWORD *)_qdf_mem_malloc(0x1C0u, "wlan_crypto_vdev_obj_create_handler", 596);
  if ( !v2 )
    return 2;
  v2[1] = 0;
  v2[2] = 0;
  v3 = (__int64)v2;
  *v2 = 0;
  v4 = *(_QWORD *)(a1 + 216);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v4 + 1248);
  }
  else
  {
    raw_spin_lock_bh(v4 + 1248);
    *(_QWORD *)(v4 + 1256) |= 1uLL;
  }
  v6 = *(_DWORD *)(v4 + 8);
  v7 = *(_DWORD *)(v3 + 16);
  if ( (v6 & 1) != 0 )
  {
    v7 |= 0x20u;
    *(_DWORD *)(v3 + 16) = v7;
    v6 = *(_DWORD *)(v4 + 8);
    if ( (v6 & 2) == 0 )
    {
LABEL_9:
      if ( (v6 & 4) == 0 )
        goto LABEL_10;
      goto LABEL_27;
    }
  }
  else if ( (v6 & 2) == 0 )
  {
    goto LABEL_9;
  }
  v7 |= 0x80u;
  *(_DWORD *)(v3 + 16) = v7;
  v6 = *(_DWORD *)(v4 + 8);
  if ( (v6 & 4) == 0 )
  {
LABEL_10:
    if ( (v6 & 0x20) == 0 )
      goto LABEL_12;
    goto LABEL_11;
  }
LABEL_27:
  v7 |= 0x710u;
  *(_DWORD *)(v3 + 16) = v7;
  v6 = *(_DWORD *)(v4 + 8);
  if ( (v6 & 0x20) != 0 )
  {
LABEL_11:
    v7 |= 0x40u;
    *(_DWORD *)(v3 + 16) = v7;
    v6 = *(_DWORD *)(v4 + 8);
  }
LABEL_12:
  *(_DWORD *)(v3 + 16) = v7 | (v6 >> 6) & 0x800 | 0x10000;
  v8 = *(_QWORD *)(v4 + 1256);
  if ( (v8 & 1) == 0 )
  {
    raw_spin_unlock(v4 + 1248);
    v9 = *(_DWORD *)(v3 + 16);
    if ( (v9 & 0x20) == 0 )
      goto LABEL_15;
    goto LABEL_14;
  }
  *(_QWORD *)(v4 + 1256) = v8 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(v4 + 1248);
  v9 = *(_DWORD *)(v3 + 16);
  if ( (v9 & 0x20) != 0 )
LABEL_14:
    wlan_crypto_cipher_ops[0] = 0;
LABEL_15:
  if ( (v9 & 0x80) != 0 )
  {
    qword_826680 = 0;
    if ( (v9 & 0x10) == 0 )
    {
LABEL_17:
      if ( (v9 & 0x800) == 0 )
        goto LABEL_18;
      goto LABEL_31;
    }
  }
  else if ( (v9 & 0x10) == 0 )
  {
    goto LABEL_17;
  }
  qword_826690 = 0;
  qword_8266B0 = 0;
  qword_8266C0 = 0;
  qword_8266C8 = 0;
  v9 = *(_DWORD *)(v3 + 16);
  if ( (v9 & 0x800) == 0 )
  {
LABEL_18:
    if ( (v9 & 0x10000) == 0 )
      goto LABEL_20;
    goto LABEL_19;
  }
LABEL_31:
  qword_826698 = 0;
  if ( (*(_DWORD *)(v3 + 16) & 0x10000) != 0 )
LABEL_19:
    qword_8266E8 = 0;
LABEL_20:
  result = wlan_objmgr_vdev_component_obj_attach(a1, 14, v3, 0);
  if ( (_DWORD)result )
  {
    v11 = result;
    _qdf_mem_free(v3);
    return v11;
  }
  return result;
}
