__int64 __fastcall qos_release_command(__int64 a1, _DWORD *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  qdf_mem_set(a2 + 8, 0x54u, 0);
  return csr_release_command(a1, a2, v4, v5, v6, v7, v8, v9, v10, v11);
}
