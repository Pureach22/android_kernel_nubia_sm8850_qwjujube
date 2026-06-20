__int64 __fastcall aw882xx_dev_get_prof_data(__int64 a1, __int64 a2, int a3)
{
  __int64 *v4; // x9
  __int64 v5; // x1
  __int64 *v6; // x8
  __int64 v7; // x1

  if ( *(_DWORD *)(a1 + 624) <= (unsigned int)a2 )
  {
    v4 = *(__int64 **)(a1 + 112);
    v5 = v4[14];
    if ( !v5 )
      v5 = *v4;
    printk(&unk_23A95, v5, "aw882xx_dev_get_prof_data");
    return 0;
  }
  else if ( a3 >= 3 )
  {
    v6 = *(__int64 **)(a1 + 112);
    v7 = v6[14];
    if ( !v7 )
      v7 = *v6;
    printk(&unk_27384, v7, "aw882xx_dev_get_prof_data");
    return 0;
  }
  else if ( (unsigned int)a3 >= 4 )
  {
    __break(0x5512u);
    return aw882xx_dev_set_profile_index(a1, a2);
  }
  else
  {
    return *(_QWORD *)(a1 + 640) + ((__int64)(int)a2 << 6) + 16LL * (unsigned int)a3 + 16;
  }
}
