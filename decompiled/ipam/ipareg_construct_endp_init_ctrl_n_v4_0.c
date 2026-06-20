void __fastcall ipareg_construct_endp_init_ctrl_n_v4_0(__int64 a1, _BYTE *a2, _DWORD *a3)
{
  if ( *a2 == 1 )
    __break(0x800u);
  *a3 |= 2 * (unsigned __int8)a2[1];
}
