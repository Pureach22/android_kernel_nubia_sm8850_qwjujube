__int64 __fastcall cam_ife_csid_check_in_port_args(__int64 a1, unsigned int a2)
{
  _DWORD *v2; // x9
  unsigned int v3; // w7
  const char *v4; // x5
  __int64 v5; // x4
  unsigned int v6; // w8
  unsigned int v8; // w8

  v2 = *(_DWORD **)(a1 + 8);
  v3 = v2[2];
  if ( v3 < 0x400B )
  {
    v6 = v2[3];
    if ( v3 == 0x4000 || v6 < 2 )
    {
      if ( v6 == 1 )
      {
        if ( v3 != 0x4000 && v2[4] >= 4u )
        {
          v4 = " CSID:%d Invalid lane type %d & num %d";
          v5 = 558;
          goto LABEL_6;
        }
      }
      else if ( !v6 && v3 != 0x4000 && v2[4] >= 5u )
      {
        v4 = "CSID:%d Invalid lane num %d";
        v5 = 547;
        goto LABEL_6;
      }
      if ( (unsigned int)(*(_DWORD *)(a1 + 4) - 5) > 1 )
        return 0;
      v8 = v2[15];
      if ( v8 <= 0x32 && ((1LL << v8) & 0x440047E0000FELL) != 0 )
        return 0;
      v4 = "CSID %d, res_id %d, unsupported format %d";
      v5 = 569;
    }
    else
    {
      v4 = "CSID:%d  Invalid lane type %d";
      v5 = 538;
    }
  }
  else
  {
    v4 = "CSID:%d  Invalid phy sel %d";
    v5 = 530;
  }
LABEL_6:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_csid_check_in_port_args",
    v5,
    v4,
    a2);
  return 4294967274LL;
}
