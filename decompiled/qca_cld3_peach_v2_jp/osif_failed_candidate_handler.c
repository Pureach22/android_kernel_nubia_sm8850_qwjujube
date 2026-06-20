__int64 __fastcall osif_failed_candidate_handler(__int64 a1, unsigned __int8 *a2)
{
  const char *v4; // x22
  int v5; // w8
  __int64 v6; // x21
  const char *v7; // x5
  const char *v8; // x9
  unsigned int v9; // w8
  _QWORD v11[6]; // [xsp+60h] [xbp-40h] BYREF
  __int16 v12; // [xsp+90h] [xbp-10h]
  __int64 v13; // [xsp+98h] [xbp-8h]

  v4 = "SUCCESS";
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *((_DWORD *)a2 + 13);
  v6 = *(_QWORD *)(a1 + 608);
  v12 = 0;
  memset(v11, 0, sizeof(v11));
  if ( v5 )
  {
    v7 = (a2[1] & 0x20) != 0 ? ", Send disconnect" : (const char *)&unk_8B9E43;
    scnprintf(v11, 50, "reason %d status %d %s", *((_DWORD *)a2 + 14), *((_DWORD *)a2 + 15), v7);
    if ( *((_DWORD *)a2 + 13) )
      v4 = "FAILURE";
  }
  v8 = "Roam";
  if ( (a2[1] & 4) == 0 )
    v8 = "Connect";
  qdf_trace_msg(
    72,
    4,
    "%s(vdevid-%d): %02x:%02x:%02x:**:**:%02x %s with %02x:%02x:%02x:**:**:%02x \"%.*s\" is %s, freq %d cmid 0x%x %s",
    (const char *)(*(_QWORD *)(*(_QWORD *)v6 + 32LL) + 296LL),
    *a2,
    *(unsigned __int8 *)(a1 + 74),
    *(unsigned __int8 *)(a1 + 75),
    *(unsigned __int8 *)(a1 + 76),
    *(unsigned __int8 *)(a1 + 79),
    v8,
    a2[8],
    a2[9],
    a2[10],
    a2[13],
    a2[14],
    (const char *)a2 + 15,
    v4,
    *((_DWORD *)a2 + 12),
    *((_DWORD *)a2 + 1),
    (const char *)v11);
  if ( *((_DWORD *)a2 + 13) )
  {
    if ( (ucfg_cm_is_link_switch_connect_resp(a2) & 1) == 0 )
    {
      v9 = *((_DWORD *)a2 + 14);
      if ( v9 <= 0xA && ((1 << v9) & 0x542) != 0 )
        osif_cm_unlink_bss(a1, a2 + 8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
