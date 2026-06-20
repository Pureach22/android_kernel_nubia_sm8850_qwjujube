__int64 __fastcall aw882xx_dev_get_prof_name(__int64 a1, unsigned int a2)
{
  __int64 *v3; // x8
  __int64 v4; // x1
  __int64 *v5; // x8
  __int64 v6; // x1

  if ( (a2 & 0x80000000) != 0 )
  {
    v3 = *(__int64 **)(a1 + 112);
    v4 = v3[14];
    if ( !v4 )
      v4 = *v3;
    printk(&unk_23EF3, v4, "aw882xx_dev_get_prof_name");
    return 0;
  }
  else if ( *(_DWORD *)(a1 + 624) <= a2 )
  {
    v5 = *(__int64 **)(a1 + 112);
    v6 = v5[14];
    if ( !v6 )
      v6 = *v5;
    printk(&unk_23A95, v6, "aw882xx_dev_get_prof_name");
    return 0;
  }
  else
  {
    return *(_QWORD *)(*(_QWORD *)(a1 + 632)
                     + 8LL * *(unsigned int *)(*(_QWORD *)(a1 + 640) + ((unsigned __int64)a2 << 6) + 4));
  }
}
