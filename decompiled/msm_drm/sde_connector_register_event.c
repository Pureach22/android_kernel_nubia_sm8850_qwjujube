__int64 __fastcall sde_connector_register_event(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 v9; // x8
  _DWORD *v10; // x8
  __int64 *v11; // x9
  __int64 v12; // x3

  if ( a1 )
  {
    if ( a2 >= 5 )
    {
      printk(&unk_257702, "sde_connector_register_event");
      return 4294967274LL;
    }
    else
    {
      v8 = raw_spin_lock_irqsave(a1 + 4352);
      v9 = a1 + 16LL * a2;
      *(_QWORD *)(v9 + 4272) = a3;
      *(_QWORD *)(v9 + 4280) = a4;
      raw_spin_unlock_irqrestore(a1 + 4352, v8);
      v10 = *(_DWORD **)(a1 + 2960);
      if ( v10 )
      {
        v11 = *(__int64 **)(a1 + 2760);
        if ( v11 )
        {
          if ( *(_DWORD *)(a1 + 2736) == 16 )
          {
            if ( !*(_BYTE *)(a1 + 5128) )
              v11 = (__int64 *)(a1 + 2760);
            v12 = *v11;
          }
          else
          {
            v12 = 0;
          }
          if ( *(v10 - 1) != -1461547397 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, bool, __int64))v10)(a1, a2, a3 != 0, v12);
        }
      }
      return 0;
    }
  }
  else
  {
    printk(&unk_242658, "sde_connector_register_event");
    return 4294967274LL;
  }
}
