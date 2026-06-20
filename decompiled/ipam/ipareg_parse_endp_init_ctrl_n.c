void __fastcall ipareg_parse_endp_init_ctrl_n(__int64 a1, _BYTE *a2, char a3)
{
  *a2 = a3 & 1;
  a2[1] = (a3 & 2) != 0;
}
