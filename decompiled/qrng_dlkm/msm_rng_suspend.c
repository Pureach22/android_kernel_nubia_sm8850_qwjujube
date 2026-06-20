__int64 __fastcall msm_rng_suspend(__int64 a1)
{
  *(_BYTE *)(*(_QWORD *)(a1 + 152) + 80LL) = 1;
  printk(&unk_6E92);
  return 0;
}
