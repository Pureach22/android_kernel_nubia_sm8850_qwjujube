__int64 __fastcall sub_1ECC50(__int64 a1, __int64 _X1)
{
  __asm { SUBG            SP, X1, #0xD0, #0xB }
  return dsi_host_transfer();
}
