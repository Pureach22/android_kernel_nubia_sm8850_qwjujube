__int64 __fastcall drv_channel_switch_beacon(__int64 result, __int64 a2)
{
  __int64 v2; // x9
  __int64 v4; // x1
  __int64 v5; // x0
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x10

  v2 = *(_QWORD *)(result + 1616);
  if ( *(_QWORD *)(*(_QWORD *)(v2 + 464) + 656LL) )
  {
    v4 = result + 4720;
    v5 = *(_QWORD *)(result + 1616);
    v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v2 + 464) + 656LL);
    if ( *((_DWORD *)v6 - 1) != 795902348 )
      __break(0x822Au);
    return v6(v5, v4, a2);
  }
  return result;
}
