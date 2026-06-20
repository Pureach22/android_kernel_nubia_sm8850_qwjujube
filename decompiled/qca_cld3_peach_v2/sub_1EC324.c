__int64 __fastcall sub_1EC324(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 _X4)
{
  __asm { SUBG            X11, X4, #0x280, #1 }
  return mlme_ser_inc_act_cmd_timeout();
}
