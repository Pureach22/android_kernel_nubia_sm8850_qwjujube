__int64 __fastcall osif_cm_set_fils_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  __int64 v4; // x20
  unsigned int v7; // w4
  int v8; // w9
  __int64 result; // x0
  unsigned __int8 v10; // w10
  int v11; // w8
  int v12; // w5
  int fils_enabled_info; // w0
  unsigned int v14; // w4
  unsigned int v15; // w4
  int v16; // w6
  int v17; // w4
  __int64 v18; // x19
  _BYTE *v19; // x0
  _BYTE v20[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 216);
  v20[0] = 0;
  if ( !v3 || (v4 = *(_QWORD *)(v3 + 80)) == 0 )
  {
    result = 4294967292LL;
    goto LABEL_31;
  }
  v7 = *(_DWORD *)(a3 + 48) - 5;
  if ( v7 > 2 )
  {
    v7 = 3;
    *(_DWORD *)(a2 + 804) = 3;
    v8 = *(_DWORD *)(a3 + 112);
    if ( v8 < 1 || *(_DWORD *)(a3 + 48) )
      goto LABEL_12;
  }
  else
  {
    *(_DWORD *)(a2 + 804) = v7;
    v8 = *(_DWORD *)(a3 + 112);
    if ( v8 < 1 )
    {
LABEL_12:
      v12 = 0;
      goto LABEL_14;
    }
  }
  v10 = 0;
  while ( 1 )
  {
    v11 = *(_DWORD *)(a3 + 116 + 4LL * v10);
    if ( (unsigned int)(v11 - 1027086) <= 3 )
      break;
    if ( v8 <= (unsigned int)++v10 )
      goto LABEL_12;
  }
  qdf_trace_msg(72, 8, "%s: Fils AKM : %x", "osif_cm_is_akm_suite_fils", v11);
  v7 = *(_DWORD *)(a2 + 804);
  v12 = 1;
LABEL_14:
  *(_BYTE *)(a2 + 208) = v12;
  qdf_trace_msg(72, 8, "%s: auth type %d is fils %d", "osif_cm_set_fils_info", v7, v12);
  if ( *(_BYTE *)(a2 + 208) != 1 )
    goto LABEL_30;
  fils_enabled_info = wlan_mlme_get_fils_enabled_info(v4, v20);
  if ( fils_enabled_info || (v20[0] & 1) == 0 )
  {
    qdf_trace_msg(
      72,
      2,
      "%s: get_fils_enabled status: %d fils_enabled: %d",
      "osif_cm_set_fils_info",
      fils_enabled_info,
      v20[0]);
    result = 4;
  }
  else
  {
    if ( *(_DWORD *)(a3 + 48) == 5 )
    {
      v14 = *(_DWORD *)(a3 + 344);
      *(_DWORD *)(a2 + 472) = v14;
      if ( v14 >= 0x100 )
      {
        qdf_trace_msg(72, 2, "%s: Invalid fils realm len %d", "osif_cm_set_fils_info");
LABEL_26:
        result = 4;
        goto LABEL_31;
      }
      qdf_mem_set(a2 + 476, 0xFFu, 0);
      qdf_mem_copy(a2 + 476, *(_QWORD *)(a3 + 336), *(unsigned int *)(a2 + 472));
      *(_WORD *)(a2 + 732) = *(_WORD *)(a3 + 352) + 1;
      v15 = *(_DWORD *)(a3 + 368);
      *(_DWORD *)(a2 + 736) = v15;
      if ( v15 >= 0x41 )
      {
        qdf_trace_msg(72, 2, "%s: Invalid fils rrk len %d", "osif_cm_set_fils_info");
        goto LABEL_26;
      }
      qdf_mem_set(a2 + 740, 0x40u, 0);
      qdf_mem_copy(a2 + 740, *(_QWORD *)(a3 + 360), *(unsigned int *)(a2 + 736));
      v16 = *(_DWORD *)(a2 + 472);
      v17 = *(_DWORD *)(a3 + 328) + *(_DWORD *)(a3 + 344) + 1;
      *(_DWORD *)(a2 + 212) = v17;
      qdf_trace_msg(
        72,
        8,
        "%s: usrname len %d = usrname recv len %zu + realm len %d + %zu",
        "osif_cm_set_fils_info",
        v17,
        *(_QWORD *)(a3 + 328),
        v16,
        1u);
      if ( *(_DWORD *)(a2 + 212) >= 0xFEu )
      {
        qdf_trace_msg(72, 2, "%s: Invalid fils username len %d", "osif_cm_set_fils_info");
        goto LABEL_26;
      }
      if ( *(_QWORD *)(a3 + 328) )
      {
        v18 = a2 + 216;
        qdf_mem_set(v18, 0xFDu, 0);
        qdf_mem_copy(v18, *(_QWORD *)(a3 + 320), *(unsigned int *)(a3 + 328));
        v19 = (_BYTE *)(v18 + *(_QWORD *)(a3 + 328));
        *v19 = 64;
        qdf_mem_copy((_DWORD)v19 + 1, *(_QWORD *)(a3 + 336), *(unsigned int *)(a3 + 344));
      }
      else
      {
        qdf_trace_msg(72, 4, "%s: FILS_PMKSA: No ERP username, return success", "osif_cm_set_fils_info");
      }
LABEL_30:
      result = 0;
      goto LABEL_31;
    }
    qdf_trace_msg(72, 8, "%s: set is fils false for initial connection", "osif_cm_set_fils_info");
    result = 0;
    *(_BYTE *)(a2 + 208) = 0;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}
