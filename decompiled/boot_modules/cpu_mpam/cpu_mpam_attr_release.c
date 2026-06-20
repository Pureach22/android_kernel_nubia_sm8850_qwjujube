__int64 __fastcall cpu_mpam_attr_release(__int64 a1)
{
  kfree(*(_QWORD *)(a1 + 144));
  return kfree(a1);
}
