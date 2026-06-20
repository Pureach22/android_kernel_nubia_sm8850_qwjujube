__int64 __fastcall sub_1D170(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  _BYTE *v4; // x15

  *v4 = a4;
  return rmnet_map_process_next_hdr_packet(a1, a2, a3);
}
