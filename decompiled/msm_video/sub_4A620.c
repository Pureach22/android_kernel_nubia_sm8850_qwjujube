__int64 __fastcall sub_4A620(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a3 )
    JUMPOUT(0x13BDA8);
  return msm_v4l2_op_g_volatile_ctrl();
}
