__int64 __fastcall lim_build_p2p_ie(__int64 a1, _BYTE *a2, const void *a3, int a4)
{
  *a2 = -35;
  a2[1] = a4 + 4;
  qdf_mem_copy(a2 + 2, &unk_969516, 4u);
  qdf_mem_copy(a2 + 6, a3, (unsigned __int8)a4);
  return (unsigned int)(a4 + 6);
}
