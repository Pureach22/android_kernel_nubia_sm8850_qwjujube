__int64 __fastcall stp_policy_node_make(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v4; // x8
  __int64 v5; // x23
  unsigned __int64 v6; // x21
  __int64 v7; // x20
  void (__fastcall *v8)(_QWORD); // x8
  _UNKNOWN **v9; // x2
  unsigned __int64 StatusReg; // x24
  __int64 v11; // x25

  v2 = a1;
  if ( *(_UNKNOWN ***)(a1 + 64) != &stp_policy_type )
    v2 = *(_QWORD *)(a1 + 136);
  v4 = *(_QWORD *)(v2 + 136);
  if ( !v4 )
    return -19;
  v5 = *(_QWORD *)(v4 + 1064);
  v6 = *(_QWORD *)(v5 + 48) + 160LL;
  v7 = _kmalloc_noprof(v6, 3520);
  if ( !v7 )
    return -12;
  while ( 1 )
  {
    v8 = *(void (__fastcall **)(_QWORD))(v5 + 24);
    if ( v8 )
    {
      if ( *((_DWORD *)v8 - 1) != 251140989 )
        __break(0x8228u);
      v8(v7 + 160);
    }
    v9 = *(_QWORD *)(*(_QWORD *)(v2 + 136) + 1072LL)
       ? *(_UNKNOWN ***)(*(_QWORD *)(v2 + 136) + 1072LL)
       : &stp_policy_node_type;
    config_group_init_type_name(v7, a2, v9);
    if ( v6 >= 0x88 && (v6 & 0xFFFFFFFFFFFFFFF8LL) != 0x88 )
    {
      *(_QWORD *)(v7 + 136) = v2;
      if ( v6 >= 0x90 && (v6 & 0xFFFFFFFFFFFFFFFCLL) != 0x90 )
      {
        *(_DWORD *)(v7 + 144) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 136) + 984LL) + 16LL);
        if ( v6 >= 0x94 && (v6 & 0xFFFFFFFFFFFFFFFCLL) != 0x94 )
        {
          *(_DWORD *)(v7 + 148) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 136) + 984LL) + 20LL);
          if ( v6 >= 0x98 && (v6 & 0xFFFFFFFFFFFFFFFCLL) != 0x98 )
          {
            *(_DWORD *)(v7 + 152) = 0;
            if ( v6 >= 0x9C && (v6 & 0xFFFFFFFFFFFFFFFCLL) != 0x9C )
              break;
          }
        }
      }
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &stp_policy_node_make__alloc_tag;
    v6 = *(_QWORD *)(v5 + 48) + 160LL;
    v7 = _kmalloc_noprof(v6, 3520);
    *(_QWORD *)(StatusReg + 80) = v11;
    if ( !v7 )
      return -12;
  }
  *(_DWORD *)(v7 + 156) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 136) + 984LL) + 24LL) - 1;
  return v7;
}
