void __fastcall ipareg_parse_shared_mem_size(__int64 a1, _DWORD *a2, unsigned int a3)
{
  *a2 = (unsigned __int16)a3;
  a2[1] = HIWORD(a3);
}
