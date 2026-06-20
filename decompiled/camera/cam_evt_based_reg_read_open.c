__int64 __fastcall cam_evt_based_reg_read_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, 0, &cam_ife_set_evt_based_reg_read_info, "%16llu", a6);
}
