__int64 __fastcall handle_ht_capabilityand_ht_info(__int64 result, unsigned __int8 *a2)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x8
  bool v4; // cf
  unsigned int v5; // w8
  char v6; // w9

  v2 = *(_QWORD *)(result + 8);
  *(_BYTE *)(result + 12217) = *(unsigned __int16 *)(v2 + 1288) >> 15;
  *(_DWORD *)(result + 12220) = (*(unsigned __int16 *)(v2 + 1288) >> 2) & 3;
  *(_BYTE *)(result + 12211) = (*(_BYTE *)(v2 + 1288) & 0x10) != 0;
  *(_BYTE *)(result + 12214) = (*(_WORD *)(v2 + 1288) & 0x800) != 0;
  *(_BYTE *)(result + 12213) = (*(_BYTE *)(v2 + 1288) & 0x20) != 0;
  *(_BYTE *)(result + 12212) = (*(_BYTE *)(v2 + 1288) & 0x40) != 0;
  *(_BYTE *)(result + 12216) = (*(_WORD *)(v2 + 1288) & 0x2000) != 0;
  *(_BYTE *)(result + 12215) = (*(_WORD *)(v2 + 1288) & 0x1000) != 0;
  *(_BYTE *)(result + 12224) = (*(_BYTE *)(v2 + 1290) >> 2) & 7;
  *(_BYTE *)(result + 12226) = *(_BYTE *)(v2 + 1290) & 3;
  *(_BYTE *)(result + 12227) = *(_BYTE *)(v2 + 1293) >> 5;
  *(_BYTE *)(result + 12228) = (*(_BYTE *)(v2 + 1293) & 0x10) != 0;
  *(_DWORD *)(result + 12232) = *(_WORD *)(v2 + 1294) & 3;
  *(_BYTE *)(result + 12236) = (*(_WORD *)(v2 + 1296) & 0x400) != 0;
  *(_BYTE *)(result + 12237) = (*(_WORD *)(v2 + 1296) & 0x800) != 0;
  *(_BYTE *)(result + 12238) = *(_BYTE *)(v2 + 1297) & 1;
  *(_BYTE *)(result + 12239) = *(_BYTE *)(v2 + 1296) >> 7;
  *(_BYTE *)(result + 12240) = *(_BYTE *)(v2 + 1296) & 0x7F;
  if ( a2 )
  {
    v3 = a2[154];
    v4 = v3 >= 0xE;
    v5 = 0x3FA1u >> v3;
    v6 = !v4;
    a2[155] = v6 & v5;
    a2[7167] = (*(_WORD *)(*(_QWORD *)(result + 8) + 1296LL) & 0x200) != 0;
    return lim_init_obss_params(result, a2);
  }
  return result;
}
