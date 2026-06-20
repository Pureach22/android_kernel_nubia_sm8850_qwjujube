__int64 __fastcall sub_1398D8(__int64 a1)
{
  unsigned __int64 v1; // x23

  return cam_smmu_mini_dump_cb(a1 & 0xFFFFFFFFFFFF8000LL | (v1 >> 11) & 0x7FFF);
}
