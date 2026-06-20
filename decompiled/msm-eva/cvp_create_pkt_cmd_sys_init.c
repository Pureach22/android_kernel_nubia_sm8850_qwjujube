__int64 __fastcall cvp_create_pkt_cmd_sys_init(__int64 a1, int a2)
{
  if ( !a1 )
    return 4294967274LL;
  *(_DWORD *)(a1 + 8) = a2;
  *(_QWORD *)a1 = 0x11010010000000CLL;
  return 0;
}
