__int64 __fastcall sub_183598(__int64 a1, __int64 a2)
{
  __int64 v2; // d19
  __int64 v3; // d29

  *(_QWORD *)(a2 - 376) = v2;
  *(_QWORD *)(a2 - 368) = v3;
  return sde_hw_ctl_get_reset_status();
}
