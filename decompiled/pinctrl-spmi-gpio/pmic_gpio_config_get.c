__int64 __fastcall pmic_gpio_config_get(__int64 a1, unsigned int a2, _QWORD *a3)
{
  __int64 result; // x0
  __int64 v5; // x8
  int v6; // w8
  int v7; // w8
  int v8; // w10

  result = 4294967274LL;
  v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL) + 24LL * a2 + 16);
  switch ( *(_BYTE *)a3 )
  {
    case 1:
      if ( *(_DWORD *)(v5 + 24) == 5 )
        goto LABEL_26;
      return result;
    case 2:
      if ( (*(_BYTE *)(v5 + 2) & 1) == 0 )
        goto LABEL_26;
      return result;
    case 3:
      if ( *(_DWORD *)(v5 + 24) == 4 )
        goto LABEL_26;
      return result;
    case 5:
      if ( !*(_DWORD *)(v5 + 24) )
        goto LABEL_26;
      return result;
    case 6:
      v6 = *(_DWORD *)(v5 + 20);
      if ( v6 == 1 )
        goto LABEL_31;
      return result;
    case 7:
      if ( *(_DWORD *)(v5 + 20) == 2 )
        goto LABEL_26;
      return result;
    case 8:
      if ( !*(_DWORD *)(v5 + 20) )
        goto LABEL_26;
      return result;
    case 0xC:
      if ( (*(_BYTE *)(v5 + 7) & 1) != 0 )
      {
LABEL_26:
        v6 = 1;
        goto LABEL_31;
      }
      return result;
    case 0x12:
      v6 = *(unsigned __int8 *)(v5 + 4);
      goto LABEL_31;
    case 0x13:
      v6 = *(unsigned __int8 *)(v5 + 6);
      goto LABEL_31;
    case 0x16:
      v6 = *(_DWORD *)(v5 + 16);
      goto LABEL_31;
    case 0x80:
      v6 = *(_DWORD *)(v5 + 24);
      goto LABEL_31;
    case 0x81:
      v7 = *(_DWORD *)(v5 + 28);
      if ( v7 == 1 )
        v8 = 3;
      else
        v8 = v7;
      if ( v7 == 3 )
        v6 = 1;
      else
        v6 = v8;
      goto LABEL_31;
    case 0x82:
      v6 = *(_DWORD *)(v5 + 36);
      goto LABEL_31;
    case 0x83:
      v6 = *(unsigned __int8 *)(v5 + 8);
      goto LABEL_31;
    case 0x84:
      v6 = *(_DWORD *)(v5 + 40);
LABEL_31:
      *a3 = *(unsigned __int8 *)a3 | (unsigned int)(v6 << 8);
      result = 0;
      break;
    default:
      return result;
  }
  return result;
}
