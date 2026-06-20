__int64 __fastcall msm_rng_resume(__int64 a1)
{
  *(_BYTE *)(*(_QWORD *)(a1 + 152) + 80LL) = 0;
  printk(&unk_6D89);
  return 0;
}
