__int64 __fastcall trigout_sig_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)bitmap_print_to_pagebuf(
                1,
                a3,
                *(_QWORD *)(*(_QWORD *)(a2 + 32) + 8LL) + 8LL,
                *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 68LL));
}
