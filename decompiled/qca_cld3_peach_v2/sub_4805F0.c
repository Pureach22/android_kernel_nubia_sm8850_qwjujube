__int64 __fastcall sub_4805F0(__int64 a1)
{
  __asm { LDTR            H20, [X28,#0x8E] }
  return wlansap_get_chan_width(a1);
}
