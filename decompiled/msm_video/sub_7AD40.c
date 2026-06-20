__int64 __usercall sub_7AD40@<X0>(int a1@<W1>, int a2@<W8>)
{
  __int64 v2; // x17

  *(_DWORD *)(v2 + 216) = a1;
  *(_DWORD *)(v2 + 220) = a2;
  return validate_packet();
}
