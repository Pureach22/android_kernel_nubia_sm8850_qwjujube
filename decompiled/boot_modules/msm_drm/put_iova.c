__int64 __fastcall put_iova(__int64 a1)
{
  __int64 result; // x0
  _QWORD *v3; // x20
  _QWORD *v4; // x24
  _QWORD *v5; // x8
  _QWORD *v6; // x9

  result = mutex_is_locked(a1 + 544);
  if ( (result & 1) == 0 )
    __break(0x800u);
  v3 = *(_QWORD **)(a1 + 440);
  if ( v3 != (_QWORD *)(a1 + 440) )
  {
    do
    {
      v4 = (_QWORD *)*v3;
      result = msm_gem_unmap_vma(*(v3 - 1), v3 - 23, *(_QWORD *)(a1 + 424), *(unsigned int *)(a1 + 368));
      *(_QWORD *)(a1 + 608) = *(v3 - 1);
      if ( v3 != &qword_B8 )
      {
        v5 = (_QWORD *)v3[1];
        if ( (_QWORD *)*v5 == v3 && (v6 = (_QWORD *)*v3, *(_QWORD **)(*v3 + 8LL) == v3) )
        {
          v6[1] = v5;
          *v5 = v6;
        }
        else
        {
          _list_del_entry_valid_or_report(v3);
        }
        *v3 = 0xDEAD000000000100LL;
        v3[1] = 0xDEAD000000000122LL;
        result = kfree(v3 - 23);
      }
      v3 = v4;
    }
    while ( v4 != (_QWORD *)(a1 + 440) );
  }
  return result;
}
