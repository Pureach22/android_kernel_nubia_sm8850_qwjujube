__int64 __fastcall syna_dev_helper_work(__int64 result)
{
  __int64 v1; // x19
  __int64 *v2; // x20
  int v3; // w8
  __int64 v4; // x2
  __int64 (__fastcall *v5)(_QWORD); // x8

  v1 = result;
  if ( (unsigned __int8)*(_DWORD *)(result - 8) == 1 )
  {
    v2 = (__int64 *)(result - 1320);
    result = *(_QWORD *)(result - 1320);
    v3 = *(unsigned __int8 *)(result + 9);
    if ( v3 == 11 )
    {
      if ( (syna_tcm_get_boot_info(result, 0, 20) & 0x80000000) == 0 )
        printk(&unk_35A8D, "syna_dev_helper_work", *(unsigned __int8 *)(*v2 + 225));
      result = *v2;
      v3 = *(unsigned __int8 *)(*v2 + 9);
      if ( v3 == 11 )
      {
        queue_delayed_work_on(32, *(_QWORD *)(v1 - 248), v1 - 352, 25);
        result = *v2;
        v3 = *(unsigned __int8 *)(*v2 + 9);
      }
    }
    if ( v3 == 1 )
    {
      v4 = *(unsigned __int16 *)(result + 178);
      if ( *(_WORD *)(result + 178) )
      {
        result = printk(&unk_32FB1, "syna_dev_helper_work", v4);
        if ( *(_BYTE *)(*v2 + 9) == 11 )
          result = queue_delayed_work_on(32, *(_QWORD *)(v1 - 248), v1 - 352, 25);
      }
      else
      {
        printk(&unk_34811, "syna_dev_helper_work", v4);
        v5 = *(__int64 (__fastcall **)(_QWORD))(v1 + 400);
        if ( *((_DWORD *)v5 - 1) != -1373616356 )
          __break(0x8228u);
        result = v5(v1 - 1320);
      }
    }
  }
  *(_DWORD *)(v1 - 8) = 0;
  return result;
}
