__int64 __fastcall sub_799BC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  if ( !a5 )
    JUMPOUT(0xBCF0);
  return sta_info_alloc_with_link(a1, a2, a3, a4, a5);
}
