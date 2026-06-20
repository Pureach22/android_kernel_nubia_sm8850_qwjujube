__int64 __fastcall hif_get_fw_diag_ce_id(__int64 a1, _BYTE *a2)
{
  unsigned int v3; // w19
  int v5; // [xsp+Ch] [xbp-14h] BYREF
  int v6; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v7[3]; // [xsp+14h] [xbp-Ch] BYREF
  char v8; // [xsp+17h] [xbp-9h] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  v3 = hif_map_service_to_pipe(a1, 0x107u, &v8, v7, &v6, &v5);
  if ( v3 )
    qdf_trace_msg(61, 2, "%s: Failed to map pipe: %d", "hif_get_fw_diag_ce_id", v3);
  else
    *a2 = v7[0];
  _ReadStatusReg(SP_EL0);
  return v3;
}
