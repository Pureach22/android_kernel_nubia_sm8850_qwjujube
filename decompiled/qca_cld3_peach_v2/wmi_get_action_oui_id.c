__int64 __fastcall wmi_get_action_oui_id(unsigned int a1, _DWORD *a2)
{
  int v2; // w8

  if ( a1 > 0x12 || ((0x73FFFu >> a1) & 1) == 0 )
    return 0;
  v2 = dword_B32FA0[a1];
  *a2 = v2;
  return 1;
}
