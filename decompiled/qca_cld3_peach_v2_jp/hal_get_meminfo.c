__int64 __fastcall hal_get_meminfo(__int64 *a1, __int64 a2)
{
  __int64 result; // x0

  *(_QWORD *)a2 = a1[2];
  *(_QWORD *)(a2 + 32) = a1[9252];
  *(_QWORD *)(a2 + 48) = a1[9254];
  *(_QWORD *)(a2 + 40) = a1[9253];
  *(_QWORD *)(a2 + 56) = a1[9255];
  result = hif_read_phy_mem_base(*a1, (_QWORD *)(a2 + 8));
  *(_BYTE *)(a2 + 64) = -72;
  return result;
}
