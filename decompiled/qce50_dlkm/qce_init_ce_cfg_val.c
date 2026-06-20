__int64 __fastcall qce_init_ce_cfg_val(__int64 result)
{
  unsigned int v1; // w10
  int v2; // w8
  unsigned int v3; // w10
  int v4; // w9
  int v5; // w8
  int v6; // w8

  v1 = *(_DWORD *)(result + 400);
  v2 = *(unsigned __int8 *)(result + 70261);
  *(_QWORD *)(result + 156) = 0x5200000042LL;
  v3 = v1 >> 3;
  if ( v2 )
    v4 = 15360;
  else
    v4 = 0;
  *(_QWORD *)(result + 180) = 0x9200000082LL;
  *(_QWORD *)(result + 172) = 0xD2000000C2LL;
  *(_QWORD *)(result + 188) = 0x211200002102LL;
  *(_QWORD *)(result + 164) = 0x1200000002LL;
  v5 = *(_DWORD *)(result + 316);
  *(_QWORD *)(result + 196) = 0x100000041LL;
  v6 = ((v4 & 0x1FFFF | ((unsigned __int16)v3 << 17)) - 0x20000) | (32 * v5);
  *(_QWORD *)(result + 204) = 0x900000049LL;
  *(_QWORD *)(result + 212) = 0x500000004LL;
  *(_DWORD *)(result + 148) = v6 | 0xE;
  *(_DWORD *)(result + 152) = v6 | 0x20E;
  *(_DWORD *)(result + 220) = 204354;
  *(_DWORD *)(result + 224) = 204370;
  *(_DWORD *)(result + 260) = 196611;
  *(_QWORD *)(result + 236) = 0x24100000041LL;
  *(_QWORD *)(result + 228) = 0x20100000001LL;
  *(_DWORD *)(result + 252) = 196673;
  *(_DWORD *)(result + 256) = 197185;
  *(_DWORD *)(result + 244) = 4390914;
  *(_DWORD *)(result + 248) = 4390930;
  *(_DWORD *)(result + 264) = 196612;
  *(_QWORD *)(result + 268) = -1;
  *(_QWORD *)(result + 276) = -1;
  return result;
}
