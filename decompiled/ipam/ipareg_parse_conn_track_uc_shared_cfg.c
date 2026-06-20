void __fastcall ipareg_parse_conn_track_uc_shared_cfg(__int64 a1, _DWORD *a2, int a3)
{
  unsigned __int64 v3; // t2

  HIDWORD(v3) = a3;
  LODWORD(v3) = a3;
  *a2 = v3 >> 16;
}
