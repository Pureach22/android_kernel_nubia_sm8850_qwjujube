_WORD *__fastcall synx_global_get_waiting_cores_locked(__int64 a1, _BYTE *a2)
{
  _WORD *result; // x0
  __int64 v5; // x5

  result = synx_global_print_data((_WORD *)a1, (__int64)"synx_global_get_waiting_cores_locked");
  if ( (*(_WORD *)(a1 + 14) & 1) != 0 && (*a2 = 1, (synx_debug & 0x10) != 0) )
  {
    result = (_WORD *)printk(
                        &unk_2754C,
                        "verb",
                        "synx_global_get_waiting_cores_locked",
                        372,
                        *(unsigned int *)(a1 + 4),
                        v5);
    if ( (*(_WORD *)(a1 + 14) & 2) == 0 )
      goto LABEL_6;
  }
  else if ( (*(_WORD *)(a1 + 14) & 2) == 0 )
  {
    goto LABEL_6;
  }
  a2[1] = 1;
  if ( (synx_debug & 0x10) != 0 )
    result = (_WORD *)printk(
                        &unk_2754C,
                        "verb",
                        "synx_global_get_waiting_cores_locked",
                        372,
                        *(unsigned int *)(a1 + 4),
                        v5);
LABEL_6:
  if ( (*(_WORD *)(a1 + 14) & 4) != 0 && (a2[2] = 1, (synx_debug & 0x10) != 0) )
  {
    result = (_WORD *)printk(
                        &unk_2754C,
                        "verb",
                        "synx_global_get_waiting_cores_locked",
                        372,
                        *(unsigned int *)(a1 + 4),
                        v5);
    if ( (*(_WORD *)(a1 + 14) & 8) == 0 )
      goto LABEL_11;
  }
  else if ( (*(_WORD *)(a1 + 14) & 8) == 0 )
  {
    goto LABEL_11;
  }
  a2[3] = 1;
  if ( (synx_debug & 0x10) != 0 )
    result = (_WORD *)printk(
                        &unk_2754C,
                        "verb",
                        "synx_global_get_waiting_cores_locked",
                        372,
                        *(unsigned int *)(a1 + 4),
                        v5);
LABEL_11:
  if ( (*(_WORD *)(a1 + 14) & 0x10) != 0 && (a2[4] = 1, (synx_debug & 0x10) != 0) )
  {
    result = (_WORD *)printk(
                        &unk_2754C,
                        "verb",
                        "synx_global_get_waiting_cores_locked",
                        372,
                        *(unsigned int *)(a1 + 4),
                        v5);
    if ( (*(_WORD *)(a1 + 14) & 0x20) == 0 )
      goto LABEL_16;
  }
  else if ( (*(_WORD *)(a1 + 14) & 0x20) == 0 )
  {
    goto LABEL_16;
  }
  a2[5] = 1;
  if ( (synx_debug & 0x10) != 0 )
    result = (_WORD *)printk(
                        &unk_2754C,
                        "verb",
                        "synx_global_get_waiting_cores_locked",
                        372,
                        *(unsigned int *)(a1 + 4),
                        v5);
LABEL_16:
  if ( (*(_WORD *)(a1 + 14) & 0x40) != 0 && (a2[6] = 1, (synx_debug & 0x10) != 0) )
  {
    result = (_WORD *)printk(
                        &unk_2754C,
                        "verb",
                        "synx_global_get_waiting_cores_locked",
                        372,
                        *(unsigned int *)(a1 + 4),
                        v5);
    if ( (*(_WORD *)(a1 + 14) & 0x80) == 0 )
      goto LABEL_21;
  }
  else if ( (*(_WORD *)(a1 + 14) & 0x80) == 0 )
  {
    goto LABEL_21;
  }
  a2[7] = 1;
  if ( (synx_debug & 0x10) != 0 )
    result = (_WORD *)printk(
                        &unk_2754C,
                        "verb",
                        "synx_global_get_waiting_cores_locked",
                        372,
                        *(unsigned int *)(a1 + 4),
                        v5);
LABEL_21:
  *(_WORD *)(a1 + 14) = 0;
  return result;
}
