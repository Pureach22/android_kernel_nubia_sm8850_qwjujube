__int64 __fastcall dwc3_resume_work(__int64 a1)
{
  _QWORD *v2; // x20
  __int64 v3; // x0
  int v4; // w3
  __int64 v5; // x8
  int v6; // w23
  __int64 v7; // x22
  unsigned int v8; // w21
  __int64 v9; // x9
  _DWORD *v10; // x9
  int property; // w0
  __int64 v12; // x9
  unsigned int v13; // w8
  unsigned int *v14; // x9
  const char *edev_name; // x0
  __int64 v16; // x8
  _DWORD *v17; // x8
  __int64 *v18; // x21
  __int64 v19; // x8
  _DWORD *v20; // x8
  int *v21; // x22
  unsigned int v22; // w9
  __int64 v23; // x8
  unsigned int *v24; // x10
  __int64 v25; // x10
  __int64 v26; // x0
  unsigned int v27; // w8
  __int64 result; // x0
  int v29; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v2 = (_QWORD *)(a1 - 568);
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 688);
  v4 = *(_DWORD *)(a1 + 224);
  v29 = 0;
  ipc_log_string(v3, "%s: resume_work: ext_idx:%d\n", "dwc3_resume_work", v4);
  v5 = *(_QWORD *)(a1 + 216);
  if ( !v5 )
    goto LABEL_5;
  if ( *(_BYTE *)(a1 + 178) == 1 && *(_BYTE *)(a1 + 64) != 1 )
  {
    v8 = 1;
  }
  else
  {
    if ( *(_DWORD *)(a1 + 184) )
    {
LABEL_5:
      v6 = 0;
      v7 = 0;
      v8 = 0;
      goto LABEL_6;
    }
    v8 = 2;
  }
  v7 = *(_QWORD *)(v5 + 80LL * *(int *)(a1 + 224));
  if ( v7 )
  {
    edev_name = (const char *)extcon_get_edev_name(*(_QWORD *)(v5 + 80LL * *(int *)(a1 + 224)));
    ipc_log_string(*(_QWORD *)(a1 + 688), "%s: edev:%s\n", "dwc3_resume_work", edev_name);
    v6 = 1;
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 216) + 80LL * *(int *)(a1 + 224) + 72) & 1) != 0 )
      goto LABEL_31;
  }
  else
  {
    v6 = 0;
  }
LABEL_6:
  if ( (*(_BYTE *)(a1 + 664) & 1) == 0 )
  {
    v9 = *(_QWORD *)(a1 - 528);
    if ( v9 )
      v10 = (_DWORD *)(*(_QWORD *)(v9 + 168) + 1232LL);
    else
      v10 = (_DWORD *)(a1 + 560);
    *v10 = *(_DWORD *)(a1 + 564);
  }
  if ( v6 )
  {
    if ( (unsigned int)extcon_get_state(v7, v8) )
    {
      property = extcon_get_property(v7, v8, 2, &v29);
      if ( !(property | v29) )
      {
        v12 = *(_QWORD *)(a1 - 528);
        v13 = *(_DWORD *)(a1 + 564);
        if ( v12 )
          v14 = (unsigned int *)(*(_QWORD *)(v12 + 168) + 1232LL);
        else
          v14 = (unsigned int *)(a1 + 560);
        if ( v13 >= 3 )
          v13 = 3;
        *v14 = v13;
      }
    }
  }
  v16 = *(_QWORD *)(a1 - 528);
  if ( v16 )
    v17 = (_DWORD *)(*(_QWORD *)(v16 + 168) + 1232LL);
  else
    v17 = (_DWORD *)(a1 + 560);
  if ( *v17 >= 5u )
    dwc3_set_ssphy_orientation_flag(v2);
LABEL_31:
  v18 = (__int64 *)(a1 - 528);
  v19 = *(_QWORD *)(a1 - 528);
  if ( v19 )
    v20 = (_DWORD *)(*(_QWORD *)(v19 + 168) + 1232LL);
  else
    v20 = (_DWORD *)(a1 + 560);
  v21 = (int *)(a1 + 560);
  ipc_log_string(
    *(_QWORD *)(a1 + 688),
    "%s: max_speed:%d hw_supp_speed:%d override_speed:%d",
    "dwc3_resume_work",
    *v20,
    *(_DWORD *)(a1 + 564),
    *(_DWORD *)(a1 + 560));
  v22 = *(_DWORD *)(a1 + 560);
  v23 = *v18;
  if ( v22 )
  {
    v24 = (unsigned int *)(a1 + 560);
    if ( v23 )
    {
      v25 = *(_QWORD *)(v23 + 168);
      if ( v22 > *(_DWORD *)(v25 + 1232) )
      {
        v26 = *(_QWORD *)(a1 + 688);
LABEL_43:
        v21 = (int *)(*(_QWORD *)(v23 + 168) + 1232LL);
        goto LABEL_44;
      }
      v24 = (unsigned int *)(v25 + 1232);
    }
    v27 = *(_DWORD *)(a1 + 564);
    if ( v27 >= v22 )
      v27 = *(_DWORD *)(a1 + 560);
    *v24 = v27;
    v23 = *v18;
  }
  v26 = *(_QWORD *)(a1 + 688);
  if ( v23 )
    goto LABEL_43;
LABEL_44:
  result = dwc3_dbg_print(v26, 0xFFu, "speed", *v21, (const char *)&unk_16A05);
  if ( ((*(_DWORD *)(a1 + 128) == 0) & ~v6) == 0 || (*(_BYTE *)(a1 - 59) & 1) != 0 )
  {
    if ( (*(_BYTE *)(a1 - 59) & 1) != 0 )
    {
      _pm_runtime_resume(*v2, 0);
      *(_BYTE *)(a1 - 59) = 0;
    }
    if ( *(_DWORD *)(a1 - 56) )
      result = dwc3_dbg_print(*(_QWORD *)(a1 + 688), 0xFFu, "RWrk PMSus", 0, (const char *)&unk_16A05);
    else
      result = dwc3_ext_event_notify((__int64)v2);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
