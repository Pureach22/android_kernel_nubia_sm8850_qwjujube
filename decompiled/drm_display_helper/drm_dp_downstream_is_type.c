bool __fastcall drm_dp_downstream_is_type(unsigned __int8 *a1, _BYTE *a2, char a3)
{
  return (a1[5] & 1) != 0 && *a1 >= 0x11u && (*a2 & 7) == a3;
}
