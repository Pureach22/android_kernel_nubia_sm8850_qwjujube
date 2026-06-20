__int64 __fastcall qmp_fu1_usage_modes_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w10
  __int64 v4; // x19
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x9
  __int64 v10; // x0
  const char *v11; // x1

  v2 = *(_QWORD *)(a1 + 128);
  v3 = *(_DWORD *)(a2 + 72);
  v4 = *(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL);
  *(_DWORD *)(v4 + 160) = v3;
  switch ( v3 )
  {
    case 2:
    case 9:
    case 19:
    case 25:
      v6 = (*(unsigned __int64 *)(v4 + 192) * (unsigned __int128)0xAAAAAAAAAAAAAAABLL) >> 64;
      goto LABEL_5;
    case 3:
    case 10:
    case 20:
    case 26:
      v6 = *(_QWORD *)(v4 + 192);
LABEL_5:
      v5 = v6 >> 1;
      goto LABEL_6;
    case 16:
      v8 = *(_QWORD *)(v4 + 192);
      if ( v8 != 12288000 )
      {
        v5 = v8 / 6;
        goto LABEL_6;
      }
      v10 = *(_QWORD *)(v2 + 24);
      v11 = "div6 unsupported for MCLK 12.288MHz, setting to div4\n";
      goto LABEL_14;
    case 17:
      v9 = *(_QWORD *)(v4 + 192);
      if ( v9 == 9600000 )
      {
        v10 = *(_QWORD *)(v2 + 24);
        v11 = "div8 unsupported for MCLK 9.288MHz, setting to div4\n";
LABEL_14:
        dev_info(v10, v11);
LABEL_2:
        v5 = *(_QWORD *)(v4 + 192) >> 2;
      }
      else
      {
        v5 = v9 >> 3;
      }
LABEL_6:
      *(_QWORD *)(v4 + 176) = v5;
      return 0;
    case 32:
      v5 = *(_QWORD *)(v4 + 192) >> 4;
      goto LABEL_6;
    default:
      goto LABEL_2;
  }
}
