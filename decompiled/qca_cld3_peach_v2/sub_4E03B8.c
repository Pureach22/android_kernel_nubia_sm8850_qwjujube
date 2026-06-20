__int64 __fastcall sub_4E03B8(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  int v7; // w30

  return wma_send_pdev_set_hw_mode_cmd(a1, a2, a3, a4, a5, a6, a7, (unsigned int)(v7 << 15 >> 14));
}
